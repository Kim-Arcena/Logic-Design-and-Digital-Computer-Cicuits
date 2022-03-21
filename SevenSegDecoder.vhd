library ieee;	
use ieee.std_logic_1164.all;

entity SevenSegDecoder is
	port(	
		SW:	in bit_vector (3 downto 0);			--4-bit type input port		
		Prime: out bit							--1 bit output
		SevenSeg : out bit_vector(6 downto 0)); --type vector  
	);

end SevenSegDecoder;


architecture SevenSegDecoder_arch of PrimeDetector is
begin	
	with (SW) select											
		Prime <= '1' WHEN "0010" |"0011" | "0101" | "0111" | "1011" | "1101",		--all prime numbers from 0-15
			'0' WHEN OTHERS;					--the remaining are composite numbers including zero which is neither
		
		SevenSeg  <=“1111110” when “0000”,		--Selected signal assignment for SevenSeg
					“0110000” when “0001”,
					“1101101” when “0010”,
					“1111001” when “0011”,
					“0110011” when “0100”,
					“1011011” when “0101”,
					“1011111” when “0110”,
					“1110000” when “0111”,
					“1111111” when “1000”,
					“1111011” when “1001”,
					“1110111” when “1010”,
					“0011111” when “1011”,
					“0001101” when “1100”,
					“0111101” when “1101”,
					“1001111” when “1110”,
					“1000111” when “1111”,
					
end SevenSegDecoder_arch;