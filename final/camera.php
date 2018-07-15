<!DOCTYPE html>
<html>
<head>
<title>UV4L Stream</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
<script src="./js/jquery-3.3.1.min.js"></script>
<!--
	Streaming script
 -->
<script>
function errorFunction() {
	alert('Stream stopped');
}
</script>
<img src="http://rasteyo.local:9000/stream/video.mjpeg" alt="image" style="transform: scale(-1, -1);" >
<br>

<!--
	control servo unit
-->
<div>
<p id='angout' text-align='center'><p>
<input type="range" id='ang' onInput="print()" min="0" max="180" 
value="<?php readfile("./tmp/angle.dat");?>" step="0.1" width="1" >
<script>
function print(){
	var tmp = document.getElementById("ang").value.toString();
	$.ajax({
	type: "GET",
	url: "./servobar.php",
	data: "message="+tmp+" ",
	success: function(html){
	}
	});
	document.getElementById('angout').innerHTML=tmp;
}
print()
</script>
</div>
</body>
</html>

