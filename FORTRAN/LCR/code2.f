        program code2
        real, dimension (100,4) :: z
        integer m
        z=0.0
        m=0
        open(1,FILE='scale.dat')
        open(2,FILE='scaleo.dat')
        open(3,FILE='freq.dat')
        print*, "No of iteration"
        read*, m
        do i=1,m
        read(3,*), z(i,1)
        end do
        do i=1,m
        read(1,*), z(i,2)
        end do
        do i=1,m
        !z(i,3)=(z(i,1)-1000)/25.0
        z(i,4)=z(i,2)*4
        write(2,*), z(i,4)
        !write(2,*),
        end do
        write(2,*),
        do i=1,m
        write(2,*), z(i,1)
        end do
        !write(2,*),
        !write(2,*),
        !write(2,*),
        !write(2,*), "########################"
        !do i=1,m
        !write(2,*), (z(i,j),j=1,2)
        !write(2,*),
        !end do
        end program code2

