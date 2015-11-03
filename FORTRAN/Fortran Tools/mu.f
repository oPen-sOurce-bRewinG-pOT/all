        program unt
        !Program for computing mu using mu lambda
        real u, a, b, c, d, e, f
        open(1,FILE='mu.dat')
250     u=0.0
	!a degree b minute c second is the angle of prism.
        a=59.0
        b=58.0
        c=5.0
        d=0.0
        e=0.0
        f=0.0
        print*,"Enter degree"
        read*, d
        if(d>0.0) then
        continue
        else
        goto 260
        end if
        print*,"Enter minute"
        read*, e
        print*,"Enter second"
        read*, f

        g=(a+(b/60)+(c/3600))*asin(1.0)/90
        h=(d+(e/60)+(f/3600))*asin(1.0)/90
        u=sin((g+h)/2)/sin(g/2)
        write(1,*),u
        write(1,*),
        goto 250
260     print*,
        end program unt
