<?php

$file = 'mat';
$norm = 0;
$fp = fopen($file, "r");
$start_time = microtime(true);

//print memory_get_usage(true)."\n";

$value = '';

while (false !== ($char = fgetc($fp))) {
	if($char !== '\n' && $char !== '\r') {
		if($char == ' ') {
			$norm += $value * $value;	
			$value = '';
		} else {
			$value .= $char;
		}
	}
}

$norm = sqrt($norm);
$end_time = microtime(true);
$total_time = $end_time - $start_time;

//print memory_get_usage(true)."\n";

print "Norm: " . $norm . "\n";
print "Execution time was: " . $total_time . " seconds\n";

