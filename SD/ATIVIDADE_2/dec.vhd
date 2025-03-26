library ieee;
use ieee.std_logic_1164.all;

entity dec is 
	port(
		data: in std_logic_vector(3 downto 0);
		a, b, c, d, e, f, g, dp: out std_logic
		-- saida: out std_logic_vector(3 downto 0)
);
end dec;

architecture meu_dec of dec is
	signal saida: std_logic_vector(7 downto 0);
	begin
		my_case : process(data)

		begin 
			case data is
				when "0000" => saida <= "11111100";
				when "0001" => saida <= "01100000";
				when "0010" => saida <= "11011010";
				when "0011" => saida <= "11110010";
				when "0100" => saida <= "01100110";
				when "0101" => saida <= "10110110";
				when "0110" => saida <= "10111110";
				when "0111" => saida <= "11100000";
				when "1000" => saida <= "11111110";
				when "1001" => saida <= "11110110";
				when others => saida <= "00000000";
			end case;
		end process;

		a<=saida(7);
		b<=saida(6);
		c<=saida(5);
		d<=saida(4);
		e<=saida(3);
		f<=saida(2);
		g<=saida(1);
		dp<=saida(0);

	end architecture meu_dec;