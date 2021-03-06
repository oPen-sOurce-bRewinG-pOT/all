c      This program calculates the determinant using Gauss Elimination
       program det
       double precision, dimension (500,500) :: a
       double precision x, y
       integer p
       open(1,file='det.dat')
       open(2,file='deto.dat')
       print*, "Enter dimension of matrix: "
       read*, n
       y=1.0d0
c      Reading the equations
       do i=1,n
       read(1,*), (a(i,j), j=1,n)
       end do
       print*,
c      Performing the elimination to form trianglar matrix
10     do i=1,n-1
       if (a(i,i) .ne. 0) then
       do j=i+1,n
       x=a(j,i)/a(i,i)
       do k=1,n
       a(j,k)=a(j,k)-x*a(i,k)
       end do
       end do
       else
       do j=1,n
       a(i,j)=a(i,j)+a(i+1,j)
       end do
       end if
       end do
       do i=1,n
       if (a(i+1,i) .ne. 0) then
       goto 10
       else
       continue
       end if
       end do
       do i=1,n
       y=y*a(i,i)
       end do
       print*, "The determinant is: ", y
       print*, 
       print*, "The reduced triangular matrix is: "      
       do m=1,n
       print*, (a(m,p),p=1,n)
       write(2,*), (a(m,p),p=1,n)
       end do
       end program det
