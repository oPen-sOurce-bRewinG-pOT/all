	PROGRAM CALC_R_S
	PRINT*, "This program lets you calculate the angle of refraction"
	PRINT*, "and reflectivity of s-polarized light due to refraction"
	PRINT*, "at the interface of the two given media, given the"
	PRINT*, "indices of refraction and incident angle."
	PRINT*, "Note that the angle should be given in degree."
	PRINT*, "The angle of refraction also comes in degree unit."
	PRINT*, ""
	PRINT*, "****************************************************"
	PRINT*, ""
	PRINT*, "Enter refractive index of first medium:"
	READ*, X	
	PRINT*, "Enter refractive index of second medium:"
	READ*, Y
	IF (X==Y) THEN
	PRINT*, "There is no interface, so no exciting activity."
	ELSE
	PRINT*, "Enter angle of incidence:"
	READ*, Ti
	IF (X<Y) THEN
	Tt=asin((X*sin(Ti*3.14159274/180))/Y)
	A=((X*cos(Ti*3.14159274/180)))
	B=((Y*cos(Tt)))
	R_S=((A-B)/(A+B))
	C=asin(X/Y)*180/3.14159274
	PRINT*, "The angle of refraction is:"
	PRINT*, Tt*180/3.14159274
	PRINT*, "The reflectivity for s polarized light is:"
	PRINT*, R_S
	PRINT*, "Critical angle for refraction from denser to rarer"
	PRINT*, "medium is:"
	PRINT*, C
	ELSE
	IF (X>Y) THEN
	PRINT*, "The critical angle is:"
	C=asin(Y/X)*180/3.14159274
	PRINT*, C
	IF (Ti<C) THEN
	Tt=asin((X*sin(Ti*3.14159274/180))/Y)
	A=((X*cos(Ti*3.14159274/180)))
	B=((Y*cos(Tt)))
	R_S=((A-B)/(A+B))
	PRINT*, "The angle of refraction is:"
	PRINT*, Tt*180/3.14159274
	PRINT*, "The reflectivity for s polarized light is:"
	PRINT*, R_S
	ELSE
	PRINT*, "The angle of incidence is greater than critical angle."
	PRINT*, "Hence, the light suffers total internal reflection with"
	PRINT*, "angle of reflection"
	PRINT*, Ti
	PRINT*, "The reflectivity is 1."
	END IF
	END IF
	END IF
	END IF
	END PROGRAM CALC_R_S

