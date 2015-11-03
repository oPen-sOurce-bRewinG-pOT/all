	PROGRAM CALC_R_S
	PRINT*, "This program lets you calculate the angle of refraction"
	PRINT*, "and reflectivity of s-polarized light due to refraction"
	PRINT*, "at the interface of the two given media, given the"
	PRINT*, "indices of refraction and incident angle."
	PRINT*, "If you want to enter angles in degree, press 1. Then"
	PRINT*, "the angle of refraction also comes in degree unit."
	PRINT*, "For radian unit, press 2."
	PRINT*, ""
	PRINT*, "****************************************************"
	PRINT*, ""
	PRINT*, "Enter unit mode (Press 1 or 2):"
	READ*, MODE
	IF (MODE==1) THEN
	PH=3.14159274/180
	HP=180/3.14159274
	ELSE
	PH=1
	HP=1
	END IF
	PRINT*, "Enter refractive index of first medium:"
	READ*, X	
	PRINT*, "Enter refractive index of second medium:"
	READ*, Y
	IF (X<1 .OR. Y<1) THEN
	PRINT*, "Please enter proper refractive indices."
	ELSE
	IF (X==Y) THEN
	PRINT*, "There is no interface, so no exciting activity."
	ELSE
	PRINT*, "Enter angle of incidence:"
	READ*, Ti
	IF (Ti<0 .OR. Ti>=90) THEN
	PRINT*, "Please enter a realistic incidence angle."
	ELSE
	IF (X<Y) THEN
	Tt=asin((X*sin(Ti*PH))/Y)
	A=((X*cos(Ti*PH)))
	B=((Y*cos(Tt)))
	R_S=((A-B)/(A+B))
	C=asin(X/Y)*HP
	A_B=atan(Y/X)*HP
	PRINT*, "The angle of refraction is:"
	PRINT*, Tt*HP
	PRINT*, "The reflectivity for s polarized light is:"
	PRINT*, R_S
	PRINT*, "Critical angle for refraction from denser to rarer"
	PRINT*, "medium is:"
	PRINT*, C
	PRINT*, "The Brewster's angle is:"
	PRINT*, A_B
	ELSE
	IF (X>Y) THEN
	PRINT*, "The critical angle is:"
	C=asin(Y/X)*HP
	PRINT*, C
	IF (Ti==C) THEN
	PRINT*, "The angle of incidence is equal to the critical angle"
	PRINT*, "during transmission from denser to rarer medium."
	PRINT*, "Hence, the reflectivity is 1 and the light grazes the"
	PRINT*, "interface."
	END IF	
	IF (Ti<C) THEN
	Tt=asin((X*sin(Ti*PH))/Y)
	A=((X*cos(Ti*PH)))
	B=((Y*cos(Tt)))
	R_S=((A-B)/(A+B))
	PRINT*, "The angle of refraction is:"
	PRINT*, Tt*HP
	PRINT*, "The reflectivity for s polarized light is:"
	PRINT*, R_S
	END IF
	IF (Ti>C) THEN
	PRINT*, "The angle of incidence is greater than critical angle."
	PRINT*, "Hence, the light suffers total internal reflection with"
	PRINT*, "angle of reflection"
	PRINT*, Ti
	PRINT*, "The reflectivity is 1."
	END IF
	END IF
	END IF
	END IF
	END IF
	END IF
	PRINT*, "The value of Pi is:"
	PRINT*, 4*atan(1.0)
	END PROGRAM CALC_R_S

