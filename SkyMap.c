#include<stdio.h>
int N;
int data[26][26];
int G = 2;
void check(int i, int j, int N)
{
    if(!(i >= 0 && j >=0 && i<=N && j <= N))
        return;
    if(data[i][j] == 1)
    {
        data[i][j] = G;
        check(i-1,j,N);
        check(i+1,j,N);
        check(i,j-1,N);
        check(i,j+1,N);
    }
}
int main(void)
{
	int test_case;
	int T;
	int temp=0;
        int max=0,num=0;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	 freopen("SkyMapSampleInput.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int i,j;
		int S,C;
                temp = num = 0;
                G=2;
		scanf("%d", &N);
		
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				scanf("%d", &data[i][j]);
			}
		}
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
                            //printf("%d",data[i][j]);
			}
                        //printf("\n");
		}
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
                            if(data[i][j] == 1)
                            {
                                check(i,j,N);
                                G++;
                            }
			}
		}

		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
                          //  printf(" %d ",data[i][j]);
			}
                        //printf("\n");
		}
                /*Find answer*/
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
                            if(data[i][j] > max)
                            {
                                temp = 0;
                                max = data[i][j];
                            }
                            if(data[i][j] ==  max)
                            {
                                temp++;
                                if(temp > num)
                                    num = temp;;
                            }
			}
		}

                printf("\n%d %d",max-1,num);
                max = num = 0;

		/**********************************
		 * Implement your algorithm here. *
		 **********************************/
		
        }
}
