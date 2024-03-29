entity SystemX_TB is
end entity;

architecture SystemX_TB_arch of SystemX_TB is

 -- Constant Declaration
  constant t_wait : time := 10 ns; 

 -- Component Declaration   
  component SystemX
    port (A, B, C  : in  bit;
          F        : out bit);
  end component;

 -- Signal Declaration
  signal   A_TB, B_TB, C_TB  : bit; -- these signals are used to connect to the device under test (DUT)
  signal   F_TB              : bit;

  begin

 -- Component Instantiation of DUT
  DUT :   SystemX
            port map (A    => A_TB,
                      B    => B_TB,
                      C    => C_TB,                    
                      F    => F_TB);

 -- Stimulus Generation
  STIMULUS : process
    begin
      A_TB <= '0'; B_TB <= '0'; C_TB <= '0'; wait for t_wait;
      A_TB <= '0'; B_TB <= '0'; C_TB <= '1'; wait for t_wait;
      A_TB <= '0'; B_TB <= '1'; C_TB <= '0'; wait for t_wait;
      A_TB <= '0'; B_TB <= '1'; C_TB <= '1'; wait for t_wait;
      A_TB <= '1'; B_TB <= '0'; C_TB <= '0'; wait for t_wait;
      A_TB <= '1'; B_TB <= '0'; C_TB <= '1'; wait for t_wait;
      A_TB <= '1'; B_TB <= '1'; C_TB <= '0'; wait for t_wait;
      A_TB <= '1'; B_TB <= '1'; C_TB <= '1'; wait for t_wait;
    end process;
      
end architecture;                
