c      Sunip Kumar Mukherjee, Physics UG 3 346.

c      This program diagonalizes any matrix, and the size can also be adjusted by changing the dimension of the
c      data matrices. Though then an automation would be recommended, as pressing 1 always for a rotation may be
c      tedious.
       program diag
       double precision, dimension (5,5) :: z, tmp      !the matrices
       double precision, dimension (10,3) :: a   !the pivoting array, dimension=\sum_1^{n-1} by 3, where n is the max allowed matrix dimension
       double precision s, c, t
       integer n, p, q, h
       open(1,file='diag.dat')
       z=0.0d0
       a=0.0d0
       h=1
       print*, "Enter dimension <= 5:"
       read*, n
       write(1,*), "The matrix to be diagonalized is: "
       write(1,*),
       print*, "Enter a SYMMETRIC matrix: "
       do i=1,n
       read*, (z(i,j),j=1,n)
       write(1,*), (z(i,j),j=1,n)
       end do
       write(1,*),
       write(1,*),
120    continue
       tmp=0.0d0
c      Calculating the trace
       trace=0.0d0
       do i=1,n
       trace=trace+z(i,i)
       end do
       print*, "The trace is: ", trace
c      Looking Off Diagonals
       k=1
       do i=1,n
       do j=n,(i+1),-1
       if (j == i) then
       continue
       else
       a(k,1)=z(i,j)
       a(k,2)=i
       a(k,3)=j
       k=k+1
       end if
       end do
       end do
       
c      Setting Pivot
       m=k-1
	do i=1,m
	l=i+1
	do 10 j=l,2,-1
102	if(a(j,1)>a(j-1,1)) then
	b=a(j-1,1)
	a(j-1,1)=a(j,1)
	a(j,1)=b
	b=a(j-1,2)
	a(j-1,2)=a(j,2)
	a(j,2)=b
	b=a(j-1,3)
	a(j-1,3)=a(j,3)
	a(j,3)=b
       else
	continue
	end if
10	continue
	end do

c      Check if the matrix is diagonal by checking the largest off diagonal element.
	if ((a(1,1) == 0).and.(a(2,1)==0).and.(a(m,1)==0)) then
	print*, "The matrix is diagonal."
	goto 779
	end if

c      Marking the locations of the pivot
       do i=1,m
       if (a(1,1)==0) then
       p=a(m,2)
       q=a(m,3)
       goto 110
       else
       p=a(1,2)
       q=a(1,3)
       goto 110
       end if
       end do
       
c      print*, p, q
c	do i=1,k-1
c      print*, (a(i,j),j=1,3)
c      end do
110    continue
c      Finding the angle of rotation
       if (z(p,p) == z(q,q)) then
       t=0.5d0*dasin(1.0d0)
       else
       t=2.0d0*z(p,q)/(z(q,q)-z(p,p))
       t=0.5d0*datan(t)
       end if
       print*, "The angle of rotation is: ", t
       if (t==0) then
       goto 779
       end if
       s=dsin(t)
       c=dcos(t)

c      Rotating the matrix
       do i=1,n
       do j=1,n
       if ((i.ne.p).and.(i.ne.q).and.(j.ne.p).and.(j.ne.q)) then
       tmp(i,j)=z(i,j)
       end if
       end do
       if ((i.ne.p).and.(i.ne.q)) then
       tmp(p,i)=c*z(p,i)-s*z(q,i)
       tmp(i,p)=tmp(p,i)
       tmp(q,i)=c*z(q,i)+s*z(p,i)
       tmp(i,q)=tmp(q,i)
       end if
       end do
       tmp(p,p)=(c*c*z(p,p))-(2.0d0*s*c*z(p,q))+(s*s*z(q,q))
       tmp(q,q)=(c*c*z(q,q))+(2.0d0*s*c*z(p,q))+(s*s*z(p,p))
       tmp(p,q)=(c*c-s*s)*z(p,q)+(s*c*(z(p,p)-z(q,q)))
       tmp(q,p)=tmp(p,q)      
       do i=1,n
       do j=1,n
       z(i,j)=tmp(i,j)
       end do
       end do 

c      Printing the rotated matrix
       print*, "The rotated matrix is: "
       print*,
       do i=1,n
       print*, (z(i,j),j=1,n)
       end do 

c      Request for further run
       print*, "Press 1 to rotate again: "
       read*, f
       if (f .ne. 1) then
       goto 778
       else
       h=h+1
       goto 120
       end if
c      Escape Sequences
779    print*, "The matrix need not be rotated any further. "
       print*,
       do i=1,n
       print*, (z(i,j),j=1,n)
       end do
       print*,
778    write(1,*), "The diagonalized matrix is: "
       write(1,*),
       do i=1,n
       write(1,*),(z(i,j),j=1,n)
       end do
       write(1,*),
       write(1,*), "The matrix has been rotated", h, "times."
777    continue
       end program diag       
