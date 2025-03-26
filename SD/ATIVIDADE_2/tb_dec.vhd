
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

entity tb_dec is
end entity;



architecture tb_dec of tb_dec is
	signal data: std_logic_vector(3 downto 0);
	signal a, b, c, d, e, f, g, dp: std_logic := '0';
    begin

	dut: entity work.dec port map (
	  data => data,
	  a => a,
	  b => b,
	  c => c,
	  d => d,
	  e => e,
	  f => f,
	  g => g,
	  dp => dp
	);

	teste: process
	begin
		wait for 100 ns;
        data <= "0000";
		wait for 100 ns;
        data <= "0001";		
		wait for 100 ns;
        data <= "0010";
		wait for 100 ns;
        data <= "0011";
		wait for 100 ns;
        data <= "0100";
		wait for 100 ns;
        data <= "0101";
		wait for 100 ns;
        data <= "0110";
		wait for 100 ns;
        data <= "0111";
		wait for 100 ns;
        data <= "1000";
		wait for 100 ns;
        data <= "1001";		
		wait for 100 ns;
        data <= "1010";
		wait for 100 ns;
        data <= "1011";
		wait for 100 ns;
        data <= "1100";
		wait for 100 ns;
        data <= "1101";
		wait for 100 ns;
        data <= "1110";
		wait for 100 ns;
        data <= "1111";
		wait;
	end process;

end architecture;
