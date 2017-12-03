color("pink")
difference()
{
    union()
    {
        //parte externa de la rueda
        difference()
        {
            union()
            {
                translate([0,0,0])cylinder(r = 34, h = 8,$fn = 100);
                for (i = [0 , 4.5])
                {
                    hull()
                    {
                        translate([0,0,1.25 + i])cylinder(r = 35.5, h = 1,$fn = 100);
                        translate([0,0,0 + i])cylinder(r = 34, h = 3.5,$fn = 100);
                    }
                }
            }
            union()
            {
                hull()
                {
                    translate([0,0,6])rotate_extrude($fn = 100)translate([29,0,8])circle(d = 8, h = 1);
                    translate([0,0,9])rotate_extrude($fn = 100)translate([27,0,8])circle(d = 10, h = 1);
                }
                
            }
        }

        // centro de la rueda
        cylinder(h = 8, d= 20, $fn = 50); //cuello eje
        hull()translate([0,0,8])rotate_extrude($fn = 50)translate([9,0,8])circle(d = 2, h = 1);//redondeo cuello
        difference() // redondeo externo cuello
        {
            cylinder(h = 5, d= 26, $fn = 50);
            translate([0,0,5])rotate_extrude($fn = 50)translate([13,0,8])circle(d = 6, h = 1);
        }
    }
    union()
    {
        eje();
        tornillo();
        for (i = [0 : 360 / 6 : 350])rotate([0,0,i])radios();
            
    }
}

//modulos hueco eje y tornillos
module eje()
{
intersection()
{
    color("blue")translate([0,0,1])cylinder(r = 2.65, h = 20, $fn = 30);
    union()
    {
    cube([3.5, 10, 20],center = true);
    translate([0,0,18])cube([10, 10, 20],center = true);
        
    }
}
}

module radios()
{
    hull()
    {
    translate([11.1,0,-1])cylinder(d = 1, h = 20,$fn = 20);
    translate([23.1,0,-1])cylinder(d = 18, h = 20,$fn = 50);
    }
}
module tornillo()
{

translate([0,0,5])rotate([0,105,0])cylinder(d = 2.8, h = 50, $fn = 20);
}