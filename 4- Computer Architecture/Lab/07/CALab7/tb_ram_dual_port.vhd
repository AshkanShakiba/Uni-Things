----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:27:47 12/13/2022 
-- Design Name: 
-- Module Name:    tb_ram_dual_port - Behavioral 
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
 
ENTITY tb_ram_dual_port IS
END tb_ram_dual_port;
 
ARCHITECTURE behavior OF tb_ram_dual_port IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ram_dual_port
    PORT(
	 --write
         wr : IN  std_logic;
	--read
         rd : IN  std_logic;
	--clk
         clk : IN  std_logic;
	--address of reading
         addr_RD : IN  std_logic_vector(4 downto 0);
	--address of writing
         addr_WR : IN  std_logic_vector(4 downto 0);
	--active low reset
         rst : IN  std_logic;
         data_in : IN  std_logic_vector(4 downto 0);
         data_out : OUT  std_logic_vector(4 downto 0);
         same : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal wr : std_logic := '0';
   signal rd : std_logic := '0';
   signal clk : std_logic := '0';
   signal addr_RD : std_logic_vector(4 downto 0) := (others => '0');
   signal addr_WR : std_logic_vector(4 downto 0) := (others => '0');
   signal rst : std_logic := '0';
   signal data_in : std_logic_vector(4 downto 0) := (others => '0');

 	--Outputs
   signal data_out : std_logic_vector(4 downto 0);
   signal same : std_logic;

  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ram_dual_port PORT MAP (
          wr => wr,
          rd => rd,
          clk => clk,
          addr_RD => addr_RD,
          addr_WR => addr_WR,
          rst => rst,
          data_in => data_in,
          data_out => data_out,
          same => same
        );

     -- Stimulus process
   stim_proc: process
   begin		
      wait for 10 ns;
		rst <='1';
		clk <= '1';
		rd <= '1';
		addr_RD <="00010";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		rst <='1';
		clk <= '1';
		rd <= '1';
		addr_RD <="00011";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		clk <= '1';
		rd <= '0';
		wr <= '1';
		data_in <= "11111";
		addr_WR <="01100";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		clk <= '1';
		rd <= '1';
		wr <= '0';
		addr_RD <="01100";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		clk <= '1';
		rd <= '1';
		addr_RD <= "11101";
		addr_WR <= "10001";
		wr <= '1';
		data_in <="00000";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		clk <= '1';
		wr <= '0';
		rd <= '1';
		addr_RD <= "00001";
		wait for 10 ns;
		clk <= '0';
		wait for 10 ns;
		clk <= '1';
		wr <= '1';
		rd <= '1';
		addr_RD <= "11001";
		addr_WR <= "11001";
      wait;
   end process;

END;

