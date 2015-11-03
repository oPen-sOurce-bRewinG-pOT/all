       program randgen
       double precision, dimension (500,500) :: a
       open(1,file='det.dat')
       print*, "Dimension:"
       read*, n
       do i=1,n
       do j=1,n
       a(i,j)=rand()
       end do
       write(1,*), (a(i,j),j=1,n)
       end do
       end program randgen

       
       
