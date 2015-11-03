c      This program solves linear equation systems.
       program jordan
       double precision, dimension (500,501) :: a
       double precision x
       open(1,file='eqninput.dat')
       print*, "Enter number of equations: "
       read*, n
c      Reading the equations
       do i=1,n
       read(1,*), (a(i,j), j=1,n+1)
       end do
       print*,
c      Applying the Gauss-Jordan Elimination       
       do i=1,n
       j=i
       do k=1,n
       x=a(k,j)
       if (x .ne. 0) then
       do l=1,n+1
       a(k,l)=a(k,l)/x
       end do
       else
       continue
       end if
       end do
       do k=1,n
       if (k.ne.i) then
       if (a(k,i) .ne. 0) then
       do l=1,n+1
       a(k,l)=a(k,l)-a(i,l)
       end do
       else
       continue
       end if
       else
       continue
       end if
       end do
       end do
c      "Normalization"      
       do i=1,n
       x=a(i,i)
       do j=1,n+1
       a(i,j)=a(i,j)/x
       end do
       end do
c      Final Output
       print*, "The solutions are: "
       print*,
       do i=1,n
       print*, (a(i,n+1))
      print*,
       end do
       
       end program jordan
