----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:50:34 12/13/2022 
-- Design Name: 
-- Module Name:    tb_ram - Behavioral 
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
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use IEEE.numeric_std.All;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_ram IS
END tb_ram;
 
ARCHITECTURE behavior OF tb_ram IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
   COMPONENT ram
	generic(
	W : integer;
	C : integer 
	);
    PORT(
         input : IN  std_logic_vector(W-1 downto 0);
         addr : IN  std_logic_vector(C-1 downto 0);
         clk : IN  std_logic;
         writeIn : IN  std_logic;
         readOut : IN  std_logic;
         rst : IN  std_logic;
         output : OUT  std_logic_vector(W-1 downto 0)
        );
    END COMPONENT;
    

	 
	constant W : integer := 8;
	constant C : integer := 2;

   --Inputs
   signal input : std_logic_vector(W-1 downto 0) := (others => '0');
   signal addr : std_logic_vector(C-1 downto 0) := (others => '0');
   signal clk : std_logic := '0';
   signal writeIn : std_logic := '0';
   signal readOut : std_logic := '0';
   signal rst : std_logic := '0';

 	--Outputs
   signal output : std_logic_vector(W-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ram 
	generic map (
	W => W,
	C => C
	)
	PORT MAP (
          input => input,
          addr => addr,
          clk => clk,
          writeIn => writeIn,
          readOut => readOut,
          rst => rst,
          output => output
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
			rst <= '1';
			
			writeIn <= '1';
			readOut <= '0';
			addr <= "00";
			input <= "10100101";
      -- hold reset state for 100 ns.
      wait for 100 ns;	
			for i in 0 to C loop	
				addr <= addr + "01";
				input <= input + "00000001";
				wait for clk_period*5;
			end loop;
			
			
			
		writeIn <= '0';
		readOut <= '1';
		addr <= "00";
      wait for 100 ns;	
		for i in 0 to C loop
			addr <= addr + "01";
			wait for clk_period*5;
		end loop;
		wait for 100 ns;
		 
		rst <= '0';
		wait for 300 ns;	
		
		
		rst <= '1';
		
		writeIn <= '0';
		readOut <= '1'	;
		addr <= "00";
      wait for 100 ns;	
		for i in 0 to C loop
			addr <= addr + "01";
			wait for clk_period*5;
		end loop;
			-- insert stimulus here 

   wait;
	
   end process;

END;

