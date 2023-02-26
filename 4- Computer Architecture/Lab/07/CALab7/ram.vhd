----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:47:59 12/13/2022 
-- Design Name: 
-- Module Name:    ram - Behavioral 
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.All;
use IEEE.math_real.all;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ram is
	generic(
	W : integer := 8;
	C : integer := 4
	);
	Port(
		input : in std_logic_vector(W - 1 downto 0);
		addr : in std_logic_vector(C-1 downto 0);
		clk : in std_logic;
		writeIn : in std_logic;
		readOut : in std_logic;
		rst : in std_logic;
		output : out std_logic_vector(W-1 downto 0)
	);
end entity ram;

architecture Behavioral of ram is
type reg is array ((2 ** C )-1 downto 0) of std_logic_vector(W-1 downto 0);
signal ramBlock : reg;
begin 

	process( clk , rst )
	begin
	if(rst = '1') then
		if(rising_edge(clk)) then
				if(writeIn = '1' and readOut = '0') then
					ramBlock(to_integer(unsigned(addr))) <= input;
				elsif (readOut = '1' and writeIn = '0') then
					output <= ramBlock(to_integer(unsigned(addr)));
				end if;
		end if;
	elsif (rst = '0') then
		for i in 0 to (2 ** c) -1 loop
			ramBlock(i) <= std_logic_vector(to_unsigned(i, W));
			end loop;
	end if;
			
end process;


end Behavioral;

