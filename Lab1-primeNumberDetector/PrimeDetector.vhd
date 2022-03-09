--library ieee;	
--use ieee.std_logic_1164.all;

entity PrimeDetector is
	port(	
		SW:	in bit_vector (3 downto 0);
		Prime: out bit
	);
end PrimeDetector;

architecture PrimeDetector_arch of PrimeDetector is
begin
	with (SW) select
		Prime <= '1' WHEN "0001" | "0010",
			'1' WHEN "0011" | "0101" | "0111" | "1011" | "1101",
			'0' WHEN OTHERS;
	
end PrimeDetector_arch;

