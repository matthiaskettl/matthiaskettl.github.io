<?php
    header('Content-Type: json');
	flush();
	set_time_limit(4600);
    // Set $to as the email you want to send the test to.
    $code = $_POST['arguments'][0];
    $email = $_POST['arguments'][1];
	
	$host    = "ibleibdahoam.ddns.net";
	$port    = 64302;
	$request_message = "REQUEST: ".$email;
	// create socket
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");
	// connect to server
	$result = socket_connect($socket, $host, $port) or die("Could not connect to server\n");  
	// send string to server
	socket_write($socket, $request_message, strlen($request_message)) or die("Could not send data to server\n");
	// get server response
	$result = socket_read ($socket, 1024) or die("Could not read server response\n");
	
	$checked = ($result == $code);
	echo $checked;
	
	socket_close($socket);

    $response_array = array("checked" => $checked);
    echo json_encode($response_array);
	flush();
?>