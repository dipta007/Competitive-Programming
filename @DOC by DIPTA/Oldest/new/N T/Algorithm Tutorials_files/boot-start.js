var UUDDLRLRBASS_bootstart = 835153841;

window.syrng_boot = {

    // Boot ID.
    id: "jsSyringeBoot",

    // Boot Version.
    bs_version: "0.1",

    // Startup delay.
    delay: 1500,

    // Partner data.
    partnerData: window['__PartnerData'] || { partnerId: "default", services: {} },

    partnerServices: window['__PartnerServices'] || null,

    // Services container.
    services: {},

    // Main controller.
    conroller: {

        // Controller run.
        run: function () {

            // Run the plugins asynchronously.
            for (var serviceName in syrng_boot.services) {

                // Get a reference to the service object.
                var service = syrng_boot.services[serviceName];

                // Validate that the service has a 'run' method.
                if (typeof service.run == "function" && service.service_id) {

                    // Run service asynchronously.
                    if (syrng_boot.partnerData.services &&
                        syrng_boot.partnerData.services[syrng_boot.services[serviceName].service_id] &&
                        (syrng_boot.partnerServices == null || syrng_boot.partnerServices[syrng_boot.services[serviceName].service_id] == true)) {

                        setTimeout(service.run, 1);

                    }

                }

            }

        }

    }

};

if (typeof syrng_continue != "undefined")
    syrng_continue();