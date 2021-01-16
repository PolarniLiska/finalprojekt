const char webstranka[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>spiska - rain detector</title>
</head>
<style>
@import url(https://fonts.googleapis.com/css?family=Montserrat);
@import url(https://fonts.googleapis.com/css?family=Advent+Pro:400,200);
*{margin: 0;padding: 0;}
 
body{
  background:#544947;
  font-family:Montserrat,Arial,sans-serif;
}
h2{
  font-size:14px;
}
.widget{
  box-shadow:0 40px 10px 5px rgba(0,0,0,0.4);
  margin:100px auto;
  height: 330px;
  position: relative;
  width: 500px;
}
 
.upper{
  border-radius:5px 5px 0 0;
  background:#f5f5f5;
  height:200px;
  padding:20px;
}
 
.date{
  font-size:40px;
}
.year{
  font-size:30px;
  color:#c1c1c1;
}
.place{
  color:#222;
  font-size:40px;
}
.lower{
  background:#00A8A9;
  border-radius:0 0 5px 5px;
  font-family:'Advent Pro';
  font-weight:200;
  height:130px;
  width:100%;
}

.infos{
 list-style:none;
 text-align:center;
}
.info{
  color:#fff;
  float:center;
  height:100%;
  padding-top:10px;
  text-align:center;
  width:25%;
}
.info span{
  display: inline-block;
  font-size:40px;
  margin-top:20px;
}

.anim{animation:fade .8s linear;}
 
@keyframes fade{
  0%{opacity:0;}
  100%{opacity:1;}
}
 
a{
 text-align: center;
 text-decoration: none;
 color: white;
 font-size: 15px;
 font-weight: 500;
}
</style>
<body>
 
 
<div class="widget"> 
  <div class="upper" style="text-align:center">
    <div class="date" id="date">2 January</div>
    <div class="year"></div>
  </div>
  <div class="lower">    
    <ul class="infos">
      <li class="info wind">
        <h2 class="title">RAIN</h2>
        <span class='update' id="rain">0%</span>
      </li>
    </ul>
  </div>
</div>
 
<script>
setInterval(drawDate, 2000);
    
function drawDate(){
    var now = new Date();
    var options = {year: 'numeric', month: 'long', day: 'numeric' };
    var today  = new Date();
    document.getElementById("date").innerHTML = today.toLocaleDateString("en-US", options);
    
    
//Get Rain Data
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
      var txt = this.responseText;
      var obj = JSON.parse(txt); //Ref: https://www.w3schools.com/js/js_json_parse.asp
        document.getElementById("rain").innerHTML = obj.Rain + "%";
      }  
    };
   xhttp.open("GET", "readADC", true); //Handle readADC server on ESP8266
   xhttp.send();
}
</script>
</body>
</html>
)=====";