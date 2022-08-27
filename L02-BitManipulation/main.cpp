#include <iostream>
#include <bitset>

using namespace std;

    /**
    Questão ùnica: Desenvolva e teste, em ambiente linux, as funções
    cujos protótipos estão abaixo descritos. Aproveite a oportunidade
    para aprender a usar o programa gdb da gnu para fazer o debug em
    linha de comando, sem o uso da interface gráfica. Mais ainda,
    aprenda a gerar a documentação desta library gerada por você
    fazendo uso do programa doxygen. Atividade Extra Opcional:
    Pesquise sobre, e adote, um dos padrões de codificação Misra C
    ou Cert C para desenvolvimento de código para sistemas críticos
    de tempo real.
    **/

    void SetBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Seta o bit da posição de memória apontada por p
        @param p Ponteiro para variável de 32bits cujo bit será setado
        @param bitn Posição do bit (0 a 31) a ser setado
        */

        *p |= (1 << bitn);
    }

    void ResetBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Reseta o bit da posição de memória apontada por p
        @param p Ponteiro para variável de 32bits cujo bit será resetado
        @param bitn Posição do bit (0 a 31) a ser resetado
        */

        *p &= ~(1 << bitn);

    }


    void ToggletBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Inverte um bit da posição de memória apontada por p
        @param p Ponteiro para variável de 32bits cujo bit será invertido
        @param bitn Posição do bit (0 a 31) a ser invertido
        */

        *p ^= (1 << bitn);

    }

    unsigned char  ReadBit(unsigned long *p, unsigned char bitn) {
        /**
        @brief Ler o bit da posição de memória apontada por p
        @param p Ponteiro para variável de 32bits cujo bit será lido
        @param bitn Posição do bit (0 a 31) a ser lido
        @return retorna o estado (0 ou 1) do bit da posição de memória apontada por p
        */

        return *p >> bitn & 0b1;
    }

    unsigned long  ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend) {
        /**
        @brief Ler uma fatia de bits da posição bitstart até bitend
        @param p Ponteiro para variável de 32bits de onde a fatia  de bits será lida
        @param bitstart Posição do bit (0 a 31) do primeiro bit a ser lido
        @param bitend Posição do bit (0 a 31) do último bit a ser lido
        @return retorna os bits de bitstart até bitend
        */

        for (int i = bitend + 1; i < 32; i++) {
            ResetBit(p, i);
            // Zera todos os bits à esquerda do que se pretende ler
            // Observe que não mudamos o número original
        }
        // Puxa para a direita, tirando os valores à direita desnecessários
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
