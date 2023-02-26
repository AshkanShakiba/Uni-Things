--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:31:03 01/23/2023
-- Design Name:   
-- Module Name:   D:/Memari/Lab/Lab_9/TB_CPU8bit.vhd
-- Project Name:  Lab_9
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CPU8bit
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY TB_CPU8bit IS
END TB_CPU8bit;
 
ARCHITECTURE behavior OF TB_CPU8bit IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CPU8bit
    PORT(
         data_in : IN  std_logic_vector(7 downto 0);
         data_out : OUT  std_logic_vector(7 downto 0);
         adress : OUT  std_logic_vector(4 downto 0);
         oe : OUT  std_logic;
         we : OUT  std_logic;
         rst : IN  std_logic;
         clk : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';

	--BiDirs
   signal data_in : std_logic_vector(7 downto 0);
   signal data_out : std_logic_vector(7 downto 0);

 	--Outputs
   signal adress : std_logic_vector(4 downto 0);
   signal oe : std_logic;
   signal we : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CPU8bit PORT MAP (
          data_in => data_in,
          data_out => data_out,
          adress => adress,
          oe => oe,
          we => we,
          rst => rst,
          clk => clk
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

		rst <= '0';
		-- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;
		rst <= '1';
		data_in <= "10100000";

      wait;
   end process;

END;
