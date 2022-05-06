entity SystemX is
	port (A, B, C : in bit;
		F	: out bit);

end entity;

architecture SystemX_arch of SystemX is

	signal An, Bn, Cn : bit;
	signal m0, m2, m6 : bit;

begin
	An <= not A;	-- NOT's
	Bn <= not B;
	Cn <= not C;

	m0 <= An and Bn and Cn;
	m2 <= An and B and Cn;
	m6 <= A and B and Cn;

	F <= m0 or m2 or m6;



end architecture;