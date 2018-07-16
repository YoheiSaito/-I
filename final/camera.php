<!DOCTYPE ht"ml>
<html>
<head>
<title>UV4L Stream</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>

img{
	transform: scale(-1, -1);
}
</style>
<meta http-equiv=”Pragma” content=”no-cache”>
<meta http-equiv=”Cache-Control” content=”no-cache”>
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
<script>
function reloadcheck(){
	$.ajax({
	url: "./reload.php",
	success: function(html){
		console.log(html);
		if(html == "t"){
			location.reload(false);
		}
	}
	});
	setTimeout(reloadcheck, 1000);
}

reloadcheck();

</script>
<img src="http://rasteyo.local:9000/stream/video.mjpeg"   style="transform: scale(-1,-1);", />

<!--
	control servo unit
-->
<div>
<p id='angout' text-align='center'><p>
<input type="range" id='ang' onInput="print()" min="0" max="180" 
value="<?php readfile("./tmp/angle.dat");?>" step="0.1" width="1" >
<script>
function print(){
	var tmp = String(document.getElementById("ang").value);
	$.ajax({
	type: "GET",
	url: "./servobar.php",
	data: "message="+tmp+" ",
	success: function(html){
	}
	});
	document.getElementById('angout').innerHTML=tmp;
}

print();
</script>
</div>
</body>
</html>

