library ieee;
use ieee.std_logic_1164.all;

entity control is 
	port(
		pos, digito: in std_logic_vector(3 downto 0);
		clk, reset: in std_logic;
        out0, out1, out2, out3, out4, out5, out6, out7: out std_logic_vector(3 downto 0)
    );
end control;

architecture meu_control of control is
    -- signal
    begin
        processo : process(reset, clk)
        begin
            if reset = '1' then
                out0, out1, out2, out3, out4, out5, out6, out7 <= "0000"; -- arruma
            elsif rising_edge(clk) then
                case pos is
                    when "0000" => out0 <= digito;
                    when "0001" => out1 <= digito;
                    when "0010" => out2 <= digito;
                    when "0011" => out3 <= digito;
                    when "0100" => out4 <= digito;
                    when "0101" => out5 <= digito;
                    when "0110" => out6 <= digito;
                    when "0111" => out7 <= digito;
                    end case;
            end if ;
            -- BLABLABLA 
            -- BLABLABLA
        end process;
    end architecture meu_control;