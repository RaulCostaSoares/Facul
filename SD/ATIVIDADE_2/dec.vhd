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
		-- case data is
		-- "0000" : a <= '1', b <= '1', c <= '1', d <= '1', e <= '1', f <= '1', g <= '0';
		elsif data = "0000" then a <= '1', b <= '1', c <= '1', d <= '1', e <= '1', f <= '1', g <= '0' else -- 0
		elsif data = "0001" then a <= '0', b <= '1', c <= '1', d <= '0', e <= '0', f <= '0', g <= '0' else -- 1
		elsif data = "0010" then  a <= '1', b <= '1', c <= '0', d <= '1', e <= '1', f <= '0', g <= '0' else  -- 2
		elsif data = "0011" then  a <= '1', b <= '1', c <= '1', d <= '1', e <= '0', f <= '0', g <= '1' else -- 3
		elsif data = "0100" then  a <= '0', b <= '1', c <= '1', d <= '0', e <= '0', f <= '1', g <= '1' else -- 4
		elsif data = "0101" then  a <= '1', b <= '0', c <= '1', d <= '1', e <= '1', f <= '0', g <= '1' else -- 5
		elsif data = "0110" then  a <= '1', b <= '0', c <= '1', d <= '1', e <= '1', f <= '1', g <= '1' else -- 6
		elsif data = "0111" then  a <= '1', b <= '1', c <= '1', d <= '0', e <= '0', f <= '0', g <= '0' else -- 7
		elsif data = "1000" then  a <= '1', b <= '1', c <= '1', d <= '1', e <= '1', f <= '1', g <= '1' else -- 8
		elsif data = "1001" then  a <= '1', b <= '1', c <= '1', d <= '1', e <= '0', f <= '1', g <= '0' else -- 9
		-- when "1010" => a <= '1'--, b <= '1', c <= '1', d <= '0', e <= '1', f <= '1', g <= '0' else -- A
		-- when "1011" => a <= '1'--, b <= '1', c <= '1', d <= '1', e <= '1', f <= '1', g <= '1' else -- B
		-- when "1100" => a <= '1'--, b <= '0', c <= '0', d <= '1', e <= '1', f <= '1', g <= '0' else -- C
		-- when "1101" => a <= '1'--, b <= '1', c <= '1', d <= '1', e <= '1', f <= '1', g <= '0' else -- D
		-- when "1110" => a <= '1'--, b <= '0', c <= '0', d <= '1', e <= '1', f <= '1', g <= '0' else -- E
		-- when "1111" => a <= '1'--, b <= '0', c <= '0', d <= '0', e <= '1', f <= '1', g <= '1' else -- F
			(others => 'X');
		end if;
	end process;
end architecture meu_dec;
