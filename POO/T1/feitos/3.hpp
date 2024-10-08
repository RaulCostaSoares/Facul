class carro{
    private:
        int ano;
        double valor, km;

    public:
        carro(int a, double b, double c);
        int getAno() const;
        double getValor() const;
        double getKm() const;
};