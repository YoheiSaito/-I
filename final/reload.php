<?php
	if(file_exists ( "./tmp/.restart" )){
		exec("rm ./tmp/.restart");
		echo "t";
	}else{
		echo "f";
	}
?>
