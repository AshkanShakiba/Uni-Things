----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:56:19 12/13/2022 
-- Design Name: 
-- Module Name:    tb_cam - Behavioral 
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_cam IS
END tb_cam;
 
ARCHITECTURE behavior OF tb_cam IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Cam
    PORT(
         rd : IN  std_logic; --READ
         wr : IN  std_logic; --WRITE
         rst : IN  std_logic; --RST
         clk : IN  std_logic; --RISING EDGE CLK
         match : out  std_logic; --MATCH PART
         data : in  std_logic_vector(3 downto 0) --DATA IN & OUT
        );
    END COMPONENT;
    

   --Inputs
   signal rd : std_logic := '0';
   signal wr : std_logic := '0';
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';
   signal match : std_logic := '0';

   signal data : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 50 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   Content_Addressable_Memory: Cam PORT MAP (
          rd => rd,
          wr => wr,
          rst => rst,
          clk => clk,
          match => match,
          data => data
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
		--empty the memory
		
      wait for clk_period;
		rst <= '1';
		wr <= '0';
		rd <= '1';
		data <= "0101"; 
		
      wait for clk_period;
		--mem(0): 0000
		wr <= '1';
		rd <= '0';
		data <= "0000"; 
		
	   wait for clk_period;	
		wr <= '1';
		rd <= '0';
		data <= "1111"; 
		--mem(1): 1111
		
		wait for clk_period;
		wr <= '0';
		rd <= '1';
		data <= "0101"; 

      wait for clk_period;
		--match: 1
		wr <= '0';
		rd <= '1';
		data <= "0000"; 
     
      wait;
   end process;

END;

