----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:54:38 12/13/2022 
-- Design Name: 
-- Module Name:    cam - Behavioral 
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
use ieee.numeric_std.all;
entity Cam is
--GENERIC PART
    generic (
	 d : INTEGER := 16;
	 c : INTEGER := 4;
    w : INTEGER := 4
	 );
	 
    port (
        rd : in std_logic; --read
        wr : in std_logic; --write
        rst : in std_logic; -- active low
        clk : in std_logic;  --rising edge clk
        match : out std_logic; --match output
        data : in std_logic_vector(w-1 downto 0)
		  addr_out: out std_logic_vector(c-1 downto 0)
    );
end Cam;

architecture Content_Addressable_Memorry of Cam is
type mem is array ((d)- 1 downto 0) of std_logic_vector(w - 1 downto 0);
signal memory : mem;

--for empty space
CONSTANT empty : std_logic_vector(w-1 downto 0) := (others => '-');

begin			
    process( rd, wr,rst, data, memory, clk)
    begin
	 --active low reset
        if (rst = '0') then 
            for i in 0 to (d)-1 loop
					 memory(i) <= empty;			 
            end loop;
				match <= '0';
		  elsif (rising_edge(clk)) then --CLK IS RISING EDGE
		  --read!!
            if(rd = '1') then
                match <= '0'; --OUTPUT=0
					 for i in 0 to (d)-1 loop
						if (data = memory(i)) then
						--match=1 if we find the data else match will be zero
							match <= '1';
							exit;
						end if;
					 end loop;
					 
            elsif(wr = '1') then --WRITE!!
					match = '0';
					for i in 0 to (d)-1 loop
					--the data that is already in memory
						if (data = memory(i)) then
							match <= '1';
							addr_out <= ieee.numeric_std(i);
							exit;
							--find the first empty space
						elsif (empty = memory(i)) then 
							memory(i) <= data; --PUT THE DATA IN THE EMPTY SPACE
							exit;
						end if;
					 end loop;
            end if;
        end if;
		  
    end process;
end Content_Addressable_Memorry;
