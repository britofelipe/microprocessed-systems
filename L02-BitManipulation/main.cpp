#include <iostream>
#include <bitset>

using namespace std;

    /**
    Quest�o �nica: Desenvolva e teste, em ambiente linux, as fun��es
    cujos prot�tipos est�o abaixo descritos. Aproveite a oportunidade
    para aprender a usar o programa gdb da gnu para fazer o debug em
    linha de comando, sem o uso da interface gr�fica. Mais ainda,
    aprenda a gerar a documenta��o desta library gerada por voc�
    fazendo uso do programa doxygen. Atividade Extra Opcional:
    Pesquise sobre, e adote, um dos padr�es de codifica��o Misra C
    ou Cert C para desenvolvimento de c�digo para sistemas cr�ticos
    de tempo real.
    **/

    void SetBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Seta o bit da posi��o de mem�ria apontada por p
        @param p Ponteiro para vari�vel de 32bits cujo bit ser� setado
        @param bitn Posi��o do bit (0 a 31) a ser setado
        */

        *p |= (1 << bitn);
    }

    void ResetBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Reseta o bit da posi��o de mem�ria apontada por p
        @param p Ponteiro para vari�vel de 32bits cujo bit ser� resetado
        @param bitn Posi��o do bit (0 a 31) a ser resetado
        */

        *p &= ~(1 << bitn);

    }


    void ToggletBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Inverte um bit da posi��o de mem�ria apontada por p
        @param p Ponteiro para vari�vel de 32bits cujo bit ser� invertido
        @param bitn Posi��o do bit (0 a 31) a ser invertido
        */

        *p ^= (1 << bitn);

    }

    unsigned char  ReadBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Ler o bit da posi��o de mem�ria apontada por p
        @param p Ponteiro para vari�vel de 32bits cujo bit ser� lido
        @param bitn Posi��o do bit (0 a 31) a ser lido
        @return retorna o estado (0 ou 1) do bit da posi��o de mem�ria apontada por p
        */

        return *p >> bitn & 0b1;
    }

    unsigned long  ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend) {
        /**
        @brief Ler uma fatia de bits da posi��o bitstart at� bitend
        @param p Ponteiro para vari�vel de 32bits de onde a fatia  de bits ser� lida
        @param bitstart Posi��o do bit (0 a 31) do primeiro bit a ser lido
        @param bitend Posi��o do bit (0 a 31) do �ltimo bit a ser lido
        @return retorna os bits de bitstart at� bitend
        */

        for (int i = bitend + 1; i < 32; i++) {
            ResetBit(p, i);
            // Zera todos os bits � esquerda do que se pretende ler
            // Observe que n�o mudamos o n�mero original
        }
        // Puxa para a direita, tirando os valores � direita desnecess�rios
        return (*p >> bitstart);
    }

    union Endian
    {
        unsigned int X;
        unsigned char Array[sizeof(int)];
    };

    unsigned char IsLittleEndian (void) {
        /**
        @brief Detecta se a arquitetura corrente armazena os dados  em formato little endian ou big endian
        @return Retorna 1 para Little endian e 0  para Big Endian
        */

        volatile union Endian Test;

        Test.X = 1;

        if(Test.Array[0] == 1)
        {
            cout << "Little Endian" << endl;
        }
        else
        {
            cout << "Big Endian" << endl;
        }
    }

int main() {

    unsigned long number = 11111011001101011001101011001100;

    std::cout<<std::bitset<32>(number)<<std::endl;

    SetBit(&number, 1);
    std::cout<<std::bitset<32>(number)<<std::endl;

    ResetBit(&number, 3);
    std::cout<<std::bitset<32>(number)<<std::endl;

    ToggletBit(&number, 0);
    std::cout<<std::bitset<32>(number)<<std::endl;

    std::cout<<std::bitset<1>(ReadBit(&number, 1))<<std::endl;

    std::cout<<std::bitset<6>(ReadBitSlice(&number, 0, 5))<<std::endl;

    IsLittleEndian();

    return 0;
}
