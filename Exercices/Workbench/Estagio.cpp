#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 1000

int main()
{

    int i, j, N, turma=1;
    struct{int codigo, media;} alunos[MAX_ALUNOS];
    struct{int max, alunos[MAX_ALUNOS];} melhores;

    scanf("%d", &N);
    while (N > 0)
    {

        for (i = 0; i < N; i++)
            scanf("%d %d", &alunos[i].codigo, &alunos[i].media);

        melhores.alunos[0] = alunos[0].codigo;
        melhores.max = alunos[0].media;
        j = 1;
        for (i = 1; i < N; i++)
        {
            if (alunos[i].media > melhores.max)
            {
                memset(melhores.alunos, 0, sizeof(melhores.alunos));
                j = 0;
                melhores.max = alunos[i].media;
                melhores.alunos[j++] = alunos[i].codigo;
            } else if (alunos[i].media == melhores.max)
            {
                melhores.alunos[j++] = alunos[i].codigo;
            }
        }
        printf("Turma %d\n", turma++);
        for (i = 0; i < j; i++)
            printf("%d ", melhores.alunos[i]);
        printf("\n\n");

        scanf("%d", &N);
    }
    return 0;
}
