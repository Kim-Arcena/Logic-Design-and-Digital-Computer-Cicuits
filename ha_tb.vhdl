library ieee;	
use ieee.std_logic_1164.all;

--tb means test bench
entity ha_tb is
	--not input and output because test bench is a complete unit. 
end ha_tb;

architecture test of ha_tb is
	component ha
		port(
			--input signal     in - input    std_ulogic - 1 bit signal
			a: in std_ulogic;
			b: in std_ulogic;
			--output signal		out - output  
			o: out std_ulogic;	-- o-variable stands for output
			c: out std_ulogic	-- c-variable stands for carryout
		);
	end component;
	
	signal a,b,o,c : std_ulogic;
begin
	--this is we're going to describe the behaviour of our test bench
	half_adder: ha port map(a => a, b => b,o => o, c => c);
	
	--create process to deliver signals sequentially and not concurrently
	process begin
	
		a <= 'X';
		b <= 'X';
		wait for 1 ns;
		
		a <= '0'; 
		b <= '0';
		wait for 1 ns;
		
		a <= '0'; 
		b <= '1';
		wait for 1 ns;
		
		a <= '1'; 
		b <= '0';
		wait for 1 ns;
		
		a <= '1'; 
		b <= '1';
		wait for 1 ns;
		
		assert false report "Reached end of test";
		wait;
		
	end process;
	
end test;
