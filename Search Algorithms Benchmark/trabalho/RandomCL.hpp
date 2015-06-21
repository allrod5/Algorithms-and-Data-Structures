#ifndef RANDOMCL_HPP_INCLUDED
#define RANDOMCL_HPP_INCLUDED

//_RANDOMCL_HPP_INCLUDED
//_RANDOMCL_HPP_INCLUDED
template <typename Tipo> // Classe Template para o gerador
class RandomCL {
	private:
		Tipo r;
		// Atributo para geração da sequência
		unsigned char i;
	public:
		RandomCL(unsigned char i) { // Construtor
			this->i = i;
			reset();
		}
		Tipo nextr() {
			r = 17*r + 23;
			return(r);
		}
		// Método da congruência linear: a=17, b=23
		void reset() { // Inicia a sequencia com a semente
			unsigned short seeds[6] = {4, 81, 151, 1601, 2307, 4207};
			r = seeds[i%6];
		}
};

#endif // RANDOMCL_HPP_INCLUDED
