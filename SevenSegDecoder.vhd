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
	
end SevenSegDecoder_arch;