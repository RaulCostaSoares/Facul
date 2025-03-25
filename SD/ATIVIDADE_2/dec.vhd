library ieee;
use ieee.std_logic_1164.all;

entity dec is port(
	data: in std_logic_vector(3 downto 0);
	a, b, c, d, e, f, g, dp: out std_logic
);
end dec;

architecture meu_dec of dec is
	begin
    my_case : process(data)
    begin 
		case data is
					when "0000" => 
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '0'; -- 0
            when "0001" => 
                a <= '0'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '0'; g <= '0'; -- 1
            when "0010" => 
                a <= '1'; b <= '1'; c <= '0'; d <= '1'; e <= '1'; f <= '0'; g <= '0'; -- 2
            when "0011" => 
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '0'; f <= '0'; g <= '1'; -- 3
            when "0100" => 
                a <= '0'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '1'; g <= '1'; -- 4
            when "0101" => 
                a <= '1'; b <= '0'; c <= '1'; d <= '1'; e <= '1'; f <= '0'; g <= '1'; -- 5
            when "0110" => 
                a <= '1'; b <= '0'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '1'; -- 6
            when "0111" => 
                a <= '1'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '0'; g <= '0'; -- 7
            when "1000" => 
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '1'; -- 8
            when "1001" => 
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '0'; f <= '1'; g <= '0'; -- 9
            when others => 
                a <= 'X'; b <= 'X'; c <= 'X'; d <= 'X'; e <= 'X'; f <= 'X'; g <= 'X'; -- Invalid input
        end case;
    end process;
end architecture meu_dec;