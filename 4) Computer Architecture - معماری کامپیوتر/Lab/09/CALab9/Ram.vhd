----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:15:10 01/23/2023 
-- Design Name: 
-- Module Name:    Ram - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
entity Ram is
    generic (
	      d : integer := 32;
			c : INTEGER := 5; 
         width : INTEGER := 8
			);
			
    port (
	     data_in : IN std_logic_vector(width-1 downto 0); --data array
        addr : IN std_logic_vector(c-1 downto 0); --address array
        w : IN std_logic; --wite		  
        r : IN std_logic; --read
        clk : IN std_logic; --clk is rising edge
        rst : IN std_logic; -- active low

		  data_out : OUT std_logic_vector(width-1 downto 0) --data array
    );			
end Ram;

architecture Behavioral of Ram is
type mem IS array (d- 1 downto 0) of std_logic_vector(width - 1 downto 0);
signal memory : mem;

begin
    process(rst, r, w, addr, data_in, clk)
    begin
        if (rst = '0') then --(active low)
		  -- Assign int values to memory address
            for i in 0 to (d-1) loop
                memory(i) <= std_logic_vector(to_unsigned(i, memory(i)'length));
            end loop;

		  elsif (rising_edge(clk)) then
		  if(r = '1' and w='0') then --read! 
               data_out <= memory(conv_integer(addr));
					
        elsif(w = '1' and r='0') then -- write!
               memory(conv_integer(addr)) <= data_in;
            end if;
				
        end if;
    end process;

end Behavioral;
