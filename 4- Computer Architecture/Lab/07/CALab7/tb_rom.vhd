----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:51:49 12/13/2022 
-- Design Name: 
-- Module Name:    tb_rom - Behavioral 
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
 
ENTITY tb_rom IS
END tb_rom;
 
ARCHITECTURE behavior OF tb_rom IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
 COMPONENT rom
   
generic(
	W : integer;
	C : integer 
	);
	Port(
		addr : in std_logic_vector(C-1 downto 0);
		clk : in std_logic;
		output : out std_logic_vector(W-1 downto 0)
	);
    END COMPONENT;
    
	constant W : integer := 8;
	constant C : integer := 2;

	
   --Inputs
   signal addr : std_logic_vector(C-1 downto 0) := (others => '0');
   signal clk : std_logic := '0';

 	--Outputs
   signal output : std_logic_vector(W-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: rom 
	generic map (
	W => W,
	C => C
	)
	PORT MAP (
          addr => addr,
          clk => clk,
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
      -- hold reset state for 100 ns.
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

