----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:02:37 01/23/2023 
-- Design Name: 
-- Module Name:    CPU8bit - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.math_real.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity CPU8bit is
	port ( 
			data_in: in std_logic_vector(7 downto 0);
			data_out: out std_logic_vector(7 downto 0);
			adress: out std_logic_vector(4 downto 0);
			oe: out std_logic;
			we: out std_logic; -- Asynchronous memory interface
			rst: in std_logic;
			clk: in std_logic);
end CPU8bit;

architecture CPU_ARCH of CPU8bit is

		type ram is array(0 to (2 ** 5) -1) of std_logic_vector(7 downto 0);
		signal ram_block : ram ;
		signal akku: std_logic_vector(8 downto 0); -- akku(8) is carry !
		signal adreg: std_logic_vector(4 downto 0);
		signal pc: std_logic_vector(4 downto 0);
		signal states: std_logic_vector(3 downto 0);
		
		signal input_signal: std_logic_vector(7 downto 0);
		signal output_signal: std_logic_vector(7 downto 0);

begin		
		Process(clk,rst) 
		begin
			If (rst = '0') then
				adreg <= (others => '0'); -- start execution at memory location 0
				states <= "0000";
				akku <= (others => '0');
				pc <= (others => '0'); 
				
				for i in 0 to 31 loop
					ram_block(i) <= "00000000";			 
            end loop;
				
				ram_block(0) <= "00011111";
				ram_block(1) <= "00111110";
				ram_block(2) <= "10011101";
				ram_block(3) <= "10111101";
				ram_block(4) <= "11000000";
				ram_block(5) <= "11100000";
				
				ram_block(29) <= "00011000";
				ram_block(31) <= "00000001";
				
			elsIf rising_edge(clk) then
				-- PC / Adress path
				If (states = "0000") then
					pc <= adreg + 1;
					adreg <= data_in(4 downto 0);
					data_out <= "ZZZZZZZZ";
				elsif (states = "1000" or 
						 states = "0100" or
						 states = "0101" or
						 states = "1010" or 
						 states = "1001" or 
						 states = "1011") then
						 
						 adreg <= pc;
						 data_out(7 downto 0) <= ram_block(conv_integer(adreg));
						 
				elsif (states = "1001") then
						 data_out(7 downto 0) <= akku(7 downto 0);
						 adreg <= pc;
				end If;
			
			-- ALU / Data Path
			Case states is
				when "1000" => akku(7 downto 0) <= data_in(7 downto 0);
				when "1001" => ram_block(conv_integer(adreg)) <= data_in(7 downto 0);
				when "1011" => akku(8) <= '0';
				when "0100" => akku(7 downto 0) <= akku(7 downto 0) and data_in(7 downto 0);
				when "0101" => akku <= ("0" & akku(7 downto 0)) + ("0" & data_in); 
				when "0110" => akku <= not akku;
				when "0111" => akku <= akku(7 downto 0) & '0';
				when others => null;
			end Case;
				-- State machine
				If (states /= "0000") then 
					states <= "0000"; -- fetch next opcode
				elsif (data_in (7 downto 5) = "011" and akku(8) = '0') then
						states <= "0000";
				elsif (data_in (7 downto 5) = "000") then
						states <= "1000";
				elsif (data_in (7 downto 5) = "001") then
						states <= "1001";
				elsif (data_in (7 downto 5) = "010") then
						states <= "1010";
				elsif (data_in (7 downto 5) = "011" and akku(8) = '1') then
						states <= "1011";
				elsif (data_in (7 downto 5) = "100") then
						states <= "0100";
				elsif (data_in (7 downto 5) = "101") then
						states <= "0101";
				elsif (data_in (7 downto 5) = "110") then
						states <= "0110";
				elsif (data_in (7 downto 5) = "111") then
						states <= "0111";
				end If;	
			end If;
		end Process;
	
		-- output
		adress <= adreg;
		--data <= "ZZZZ ZZZZ" when (states ="0100" or states ="0101");
		oe <= '1' when (clk='1' or states = "1000" or states = "0100" or states = "0101" or rst='0') else '0';
		we <= '1' when (clk='1' or states = "1001" or rst='0') else '0';

end CPU_ARCH;

