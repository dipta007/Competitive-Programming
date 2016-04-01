
document.write('<link type="image/x-icon" rel="shortcut icon" href="/i/favicon.ico"/>');
  function getGraph(url,wd,ht) {
    var last=0;
    var daHt = parseInt(ht) + parseInt('49');
    var size = "top=2,left=2,width="+wd+",height="+daHt+"status=0,resizable=yes";
    popup = window.open('/statistics/graphPopup.jsp?'+url+'&width='+wd+'&height='+ht,null,size);
    return;
  }

  function getGraph(url,wd,ht,name) {
    var last=0;
    var daHt = parseInt(ht) + parseInt('49');
    var size = "top=2,left=2,width="+wd+",height="+daHt+",status=0,resizable=yes";
    popup = window.open('/statistics/graphPopup.jsp?'+url+'&width='+wd+'&height='+ht,name,size);
    return;
  }

function tcTime() {
  w=window.open("http://www.topcoder.com/tc?module=Static&d1=calendar&d2=time","Time","top=2,left=2,width=250,height=50,resizable=yes,status=1");
  return;
}

function sponsorLink(spons) {
  w=window.open(spons,"Sponsor");
  return;
}

function sponsorLinkWindow(spons,nam,top,lef,wid,hei) {
  w=window.open(spons,nam,"top="+top+",left="+lef+",width="+wid+",height="+hei+",resizable=yes,toolbar=no,location=no,scrollbars=no,menubar=no,status=no");
  return;
}

function openWin(url, name, w, h) {
    var left = Math.round((screen.availWidth - w)/2);
    var top = Math.round((screen.availHeight-h)/2);
    win = window.open(url, name, "scrollbars=yes,toolbar=no,resizable=yes,menubar=no"
            + ",width=" + w + ",height=" + h
            + ",left=" + left + ",top=" + top);
    win.location.href = url;
    win.focus();
}

function infoWindow(url) {
  var width = 300
  var height = 250
  var left = (screen.availWidth - width) / 2;
  var top = (screen.availHeight-height)/2;
  OpenWin=this.open(url,"Info",
            "toolbar=no,menubar=no,location=no,scrollbars=yes,resizable=yes"
            + ",width=" + width + ",height=" + height
            + ",left=" + left + ",top=" + top);
}

function openProblemRating(id) {
    var width = Math.round(560);
    var height = Math.round(660);
    var left = Math.round((screen.availWidth - width) / 2);
    var top = 0;
    var cmd = "toolbar=no,menubar=no,location=no,scrollbars=yes,resizable=yes,top="+top+",left="+left+",width=" + width + ",height=" + height + ",status=0";
    var name="problemRating";
    window.open('/tc?module=ProblemRatingQuestions&pid='+id,name,cmd);
    return;
  }


function goTo(selection) {
  sel = selection.options[selection.selectedIndex].value;
  if (sel == "alltimewin")
  {
    window.location = "/stat?c=all_time_wins";
  }
  else if (sel == "winningdebuts")
  {
    window.location = "/stat?c=winning_debuts";
  }
  else if (sel == "impressivedebuts")
  {
    window.location = "/stat?c=impressive_debuts";
  }
  else if (sel == "hightesttotal")
  {
    window.location = "/stat?c=highest_totals";
  }
  else if (sel == "ratingpointgain")
  {
    window.location = "/stat?c=biggest_rating_gains";
  }
  else if (sel == "consecwins")
  {
    window.location = "/stat?c=most_consecutive_wins";
  }
  else if (sel == "submissionaccuracy")
  {
    window.location = "/stat?c=highest_accuracy";
  }
  else if (sel == "challengesuccess")
  {
    window.location = "/stat?c=best_challengers";
  }


  else {}
}


function doWrite(s) {
    document.write(s);
}