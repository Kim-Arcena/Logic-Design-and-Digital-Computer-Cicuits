library ieee;	
use ieee.std_logic_1164.all;

--Group 6 - Arceña, Madera, Sardañas

entity SevenSegDecoder is
	port(	
		SW:	in bit_vector (3 downto 0);			--4-bit type input port		
		Prime: out bit;							--1 bit output
		SevenSeg: out bit_vector(6 downto 0)	--output port is of type bit-vector
	);
end SevenSegDecoder;

architecture SevenSegDecoder_arch of SevenSegDecoder is
begin	
	with (SW) select		
		Prime <= '1' WHEN "0010" |"0011" | "0101" | "0111" | "1011" | "1101",		--all prime numbers from 0-15
			'0' WHEN OTHERS;					--the remaining are composite numbers including zero which is neither
	with (SW) select	
		SevenSeg <=	"1111110" WHEN "0000",		--apologies Sir, In our previous submission last march 21, we have forgot 
					"0110000" WHEN "0001",		--to append the SevenSeg for "0000"	
					"1101101" WHEN "0010",
					"1111001" WHEN "0011",		--Selected signal assignment for SevenSeg
					"0110011" WHEN "0100",
					"1011011" WHEN "0101",
					"1011111" WHEN "0110",
					"1110000" WHEN "0111",
					"1111111" WHEN "1000",
					"1111011" WHEN "1001",
					"1110111" WHEN "1010",
					"0011111" WHEN "1011",
					"0001101" WHEN "1100",
					"0111101" WHEN "1101",
					"1001111" WHEN "1110",
					"1000111" WHEN "1111",
					"0000000" WHEN OTHERS;

end SevenSegDecoder_arch;