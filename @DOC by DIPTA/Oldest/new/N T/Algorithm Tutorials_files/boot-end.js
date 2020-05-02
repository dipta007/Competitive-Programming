/// <reference path="boot-start.js" />

var  UUDDLRLRBASS_bootend = 835153841;

function syrng_run() {
    if (typeof window.syrng_boot == "undefined") {

        // try again a bit later
        setTimeout(syrng_run, 50);
        
    } else {

        // count the number of attributes on window.syrng_boot.services (that are not in the prototype chain)
        var serviceCount = 0;

        for (a in window.syrng_boot.services) {

            if (window.syrng_boot.services.hasOwnProperty(a)) {

                serviceCount++;

            }
        }

        // when there are 1 or more services, proceed to the next check.  Otherwise
        // try again a bit later
        if (0 >= serviceCount) {

            setTimeout(syrng_run, 50);

        } else {

            // Make sure widget has not already run in this context. (multi injection, etc)
            if (!window[syrng_boot.id]) {

                // Set the boot loaded flag to true.
                window[syrng_boot.id] = true;

                // Run the boot controller asynchronously.
                setTimeout(syrng_boot.conroller.run, syrng_boot.delay);
            }

        }

    }
}

syrng_run();