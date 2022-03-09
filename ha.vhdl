library ieee;	
use ieee.std_logic_1164.all;

entity ha is
	port(
		--input signal     in - input    std_ulogic - 1 bit signal
		a: in std_ulogic;
		b: in std_ulogic;
		--output signal		out - output  
		o: out std_ulogic;	-- o-variable stands for output
		c: out std_ulogic	-- c-variable stands for carryout
	);
end ha;

architecture behave of ha is
begin
	o <= a xor b;
	c <= a and b;
end behave;