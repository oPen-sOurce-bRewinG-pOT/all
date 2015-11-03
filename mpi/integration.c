#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

double f(double x)
{
	return (x*exp(x));
}

void timestamp ( void )
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

int main()
{
	int id, proc; long int n; double lim_low, lim_up, h, integral = 0.0; double wtime, step;
	printf("We are going to integrate exp(x) over interval of your choice and by utilizing all hardware resources that you can possibly provide. So let us begin!\n");
		fflush(stdout);
		printf("Lower limit: ");
		fflush(stdout);
		scanf("%lf", &lim_low);
		printf("Upper limit: ");
		fflush(stdout);
		scanf("%lf", &lim_up);
		printf("Number of steps: ");
		fflush(stdout);
		scanf("%li", &n);
		printf("\n");
		h = (lim_up - lim_low) / n ;
		
	//MPI init
	MPI_Init(NULL,NULL);
	//number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &proc);
	step = (lim_up - lim_low) / proc;
	//broadcast
	MPI_Bcast ( &lim_low, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
	MPI_Bcast ( &lim_up, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
	MPI_Bcast ( &h, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
	MPI_Bcast ( &step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
	//process id
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	//processor name
	char processor_name[MPI_MAX_PROCESSOR_NAME];
    	int name_len;
    	MPI_Get_processor_name(processor_name, &name_len);
	if (id == 0)
	{
		wtime = MPI_Wtime ( );
		timestamp();
		printf("\nNow we begin our calculation!\n");
	}
	double temp_low, temp_up;
	temp_low = lim_low + id*step;
	temp_up = temp_low + step;
	double integral_part = 0;
	while (temp_low < temp_up)
	{
		integral_part+=(f(temp_low)+f(temp_low+h))*h*0.50;
		temp_low+=h;
	}
	printf("The partial integral is %lf, within %lf and %lf, coming from %s %d.\n", integral_part, lim_low + id*step, temp_up, processor_name, id);
	MPI_Reduce ( &integral_part, &integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD );
	if ( id == 0 )
	{
		wtime = MPI_Wtime ( ) - wtime;
		printf("The integral is %lf, done in %lf s.\n\n", integral, wtime);
		timestamp();
		printf("\n");
	}
	MPI_Finalize();
	return 0;
}
