entity SevenSegDecoder_TB is
end entity;

architecture SevenSegDecoder_TB_arch of SevenSegDecoder_TB is

 -- Constant Declaration
  constant t_wait : time := 10 ns; 

 -- Component Declaration   
  component SevenSegDecoder
    port	(	SW		:	in	bit_vector (3 downto 0);
				Prime	: 	out	bit;
				SevenSeg : out bit_vector(6 downto 0));
  end component;

 -- Signal Declaration
  signal   SW_TB  : bit_vector (3 downto 0); -- these signals are used to connect to the device under test (DUT)
  signal   Prime_TB              : bit;
  signal   SevenSeg_TB              : bit_vector(6 downto 0);

  begin

 -- Component Instantiation of DUT
  DUT :   SevenSegDecoder
            port map (SW    => SW_TB,                    
                      Prime    => Prime_TB,
					  SevenSeg => SevenSeg_TB);

 -- Stimulus Generation
  STIMULUS : process
    begin
      SW_TB <= "0000"; wait for t_wait;
      SW_TB <= "0001"; wait for t_wait;
	  SW_TB <= "0010"; wait for t_wait;
	  SW_TB <= "0011"; wait for t_wait;
	  SW_TB <= "0100"; wait for t_wait;
	  SW_TB <= "0101"; wait for t_wait;
	  SW_TB <= "0110"; wait for t_wait;
	  SW_TB <= "0111"; wait for t_wait;
	  
	  SW_TB <= "1000"; wait for t_wait;
      SW_TB <= "1001"; wait for t_wait;
	  SW_TB <= "1010"; wait for t_wait;
	  SW_TB <= "1011"; wait for t_wait;
	  SW_TB <= "1100"; wait for t_wait;
	  SW_TB <= "1101"; wait for t_wait;
	  SW_TB <= "1110"; wait for t_wait;
	  SW_TB <= "1111"; wait for t_wait;
    end process;
      
end architecture;                
