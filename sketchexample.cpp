//This is a basic mass script using f=ma to create a wheel and that steers an object
mass compute ON
test mass <> 0                                                                  INTENT              ENTITY
    yes
        t <-0.02                                    delta time              delta time is           $deltaTime
        accel <- -force/mass                        computes acceleration   compute acceleration    $computeAccel
        velocity increaseBy 0.9 * accel *t          increase velocity       increase velocity       $increase, $velocity
        velocity multiplyBy 0.997                   damp velocity           damp velocity           $damp, $velocity
        location increaseBy velocity *t             change location         change location         $change, $location
    end

    force <- (-0.01 @-0.5 @0.01)                    set gravity             Set gravity now         $set, $gravity, $time
    //force reset //cmd to run script is force reset

//Bridge Example Force

spring compute ON
    k <- -1400                                      spring constant         set Spring constant     $set, $spring, $constantType
    v < mass1 location - mass2 location             actual length           Set length. ok what length?     $set, $length
    n <- v normalized * reset                       rest length             Set rest length for object   $set, $rest, $length, $objectType    
    f <- (v-n) * k                                  compute force           Compute force now       $computeForce $time
    mass1 addForce f.                               add to mass1            Add to Mass one         $add, $mass1
    mass2 addForce f negated.                       add to mass2            Add to Mass two         $add, $mass2