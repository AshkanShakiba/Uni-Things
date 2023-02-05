----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:48:56 12/13/2022 
-- Design Name: 
-- Module Name:    rom - Behavioral 
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


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity rom is

generic(
	W : integer := 8;
	C : integer := 4
	);
	Port(
		addr : in std_logic_vector(C-1 downto 0);
		clk : in std_logic;
		output : out std_logic_vector(W-1 downto 0)
	);
end rom;

architecture Behavioral of rom is
type reg is array ((2 ** C )-1 downto 0) of std_logic_vector(W-1 downto 0);
signal romBlock : reg:=( 
"00111000","00000001","00000010","00000011","00000100",
"00000101","00000110","00000111","00001000","00001001",
"00001010","00001011","00001100","00001101","00001110",
"00001111");
begin
	process(clk)
	begin
			if(rising_edge(clk)) then
					output <= romBlock(to_integer(unsigned(addr)));
			end if;
	end process;


end Behavioral;

