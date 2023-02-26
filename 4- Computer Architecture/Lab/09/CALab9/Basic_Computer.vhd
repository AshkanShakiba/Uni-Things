----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:45:57 01/23/2023 
-- Design Name: 
-- Module Name:    Basic_Computer - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Basic_Computer is
	port(
	arst,clk : in std_logic;
	akku : inout std_logic_vector(15 downto 0);
	irReg : out std_logic_vector(15 downto 0);
	ram0 : out std_logic_vector(15 downto 0);
		ram1 : out std_logic_vector(15 downto 0);
		ram2 : out std_logic_vector(15 downto 0);
		ram3 : out std_logic_vector(15 downto 0);
		ram4 : out std_logic_vector(15 downto 0);
		ram5 : out std_logic_vector(15 downto 0);
		ram6 : out std_logic_vector(15 downto 0);
		ram7 : out std_logic_vector(15 downto 0);
		ram8 : out std_logic_vector(15 downto 0);
		ram9 : out std_logic_vector(15 downto 0);
		ram10 : out std_logic_vector(15 downto 0);
		ram11 : out std_logic_vector(15 downto 0);
		ram12 : out std_logic_vector(15 downto 0);
		ram13 : out std_logic_vector(15 downto 0);
		ram14 : out std_logic_vector(15 downto 0);
		ram15 : out std_logic_vector(15 downto 0)
	);
end Basic_Computer;

architecture Behavioral of Basic_Computer is

type arrayOfVectors is array(15 downto 0) of std_logic_vector(15 downto 0);

begin
prcs : process(clk,arst)
variable pc,countclk : integer;
variable registers : arrayOfVectors;
variable halt,bit0 : std_logic;
variable ram : arrayOfVectors;
variable ir : std_logic_vector(15 downto 0);
variable opcode,rs,rt,offset : std_logic_vector(3 downto 0);
begin
		if(arst='1')then
			pc:=0;
			countclk:=0;
			halt:='0';
			registers(0):="0000000000000000";
			registers(1):="0000000000000001";
			registers(2):="0000000000000010";
			registers(3):="0000000000000011";
			registers(4):="0000000000000100";
			registers(5):="0000000000000101";
			registers(6):="0000000000000110";
			registers(7):="0000000000000111";
			registers(8):="0000000000001000";
			registers(9):="0000000000001001";
			registers(10):="0000000000001010";
			registers(11):="0000000000001011";
			registers(12):="0000000000001100";
			registers(13):="0000000000001101";
			registers(14):="0000000000001110";
			registers(15):="0000000000001111";
			ram(0) := "0010011000101111";--add
			ram(1) := "0011111111000100";--sub
			ram(2) := "1100011100110101";--show
			ram(3) := "1110110100110100";--shl
			ram(4) := "1111110100110100";--shr
			ram(5) := "0111011100110001";--rol
			ram(6) := "0110011100110001";--ror
			ram(7) := "1000111100011000";--and
			ram(8) := "0100011000001111";--load
			ram(9) := "0101011000001110";--store
			ram(10):= "0000101010101101";--beq
			ram(11) := "1001000000010000";--xor
			ram(12) := "1010000000000001";--or
			ram(13) := "1101101100111110";--halt
			ram(14) := "1011000001000001";--not
			ram(15) := "0001011000100001";--bneq
		elsif(Clk'event and Clk = '1')then
			if(halt='0' and pc<16)then
				countclk:=countclk+1;
				if(countclk mod 3 = 1)then --fetch
					ir:=ram(pc);
				elsif(countclk mod 3 = 2)then --decode
				opcode:=ir(15 downto 12);
				rs:=ir(11 downto 8);
				rt:=ir(7 downto 4);
				offset:=ir(3 downto 0);
				elsif(countclk mod 3 = 0)then--execution
				pc:=pc+1;
				if(opcode="0000")then --beq
					if(registers(to_integer(unsigned(rs))) = registers(to_integer(unsigned(rt))))then
						pc:=to_integer(unsigned(offset));
					end if;
				elsif(opcode="0001")then --bneq
					if(registers(to_integer(unsigned(rs))) /= registers(to_integer(unsigned(rt))))then
						pc:=to_integer(unsigned(offset));
					end if;
				elsif(opcode="0010")then --add
					akku <= registers(to_integer(unsigned(rs))) + registers(to_integer(unsigned(rt)));
				elsif(opcode="0011")then --sub
					akku <= registers(to_integer(unsigned(rs))) - registers(to_integer(unsigned(rt)));
				elsif(opcode="0100")then --load
					akku <= ram(to_integer(unsigned(offset)));
				elsif(opcode="0101")then --store
				ram(to_integer(unsigned(offset))) := akku;
				elsif(opcode="0110")then --ror
					akku <= std_logic_vector(rotate_right(unsigned((registers(to_integer(unsigned(rs))))),to_integer(unsigned(registers(to_integer(unsigned(rt)))))));
				elsif(opcode="0111")then --rol
					akku <= std_logic_vector(rotate_left(unsigned((registers(to_integer(unsigned(rs))))),to_integer(unsigned(registers(to_integer(unsigned(rt)))))));
				elsif(opcode="1000")then --and
					akku <= registers(to_integer(unsigned(rs))) and registers(to_integer(unsigned(rt)));
				elsif(opcode="1001")then --xor
					akku <= registers(to_integer(unsigned(rs))) xor registers(to_integer(unsigned(rt)));
				elsif(opcode="1010")then --or
					akku <= registers(to_integer(unsigned(rs))) or registers(to_integer(unsigned(rt)));
				elsif(opcode="1011")then --not
					akku <= not(registers(to_integer(unsigned(rs))));
				elsif(opcode="1100")then --show
					akku <= registers(to_integer(unsigned(rs)));
				elsif(opcode="1101")then --halt
					halt:='1';
				elsif(opcode="1110")then --shl
					akku <= std_logic_vector(shift_left(unsigned((registers(to_integer(unsigned(rs))))),to_integer(unsigned(registers(to_integer(unsigned(rt)))))));
				elsif(opcode="1111")then --shr
				akku <= std_logic_vector(shift_right(unsigned((registers(to_integer(unsigned(rs))))),to_integer(unsigned(registers(to_integer(unsigned(rt)))))));
				end if;
			end if;
			end if;
			
		end if;
			irReg<=ir;
			ram0 <= ram(0);
			ram1 <= ram(1);
			ram2 <= ram(2);
			ram3 <= ram(3);
			ram4 <= ram(4);
			ram5 <= ram(5);
			ram6 <= ram(6);
			ram7 <= ram(7);
			ram8 <= ram(8);
			ram9 <= ram(9);
			ram10 <= ram(10);
			ram11 <= ram(11);
			ram12 <= ram(12);
			ram13 <= ram(13);
			ram14 <= ram(14);
			ram15 <= ram(15);	
	end process;			
end Behavioral;

