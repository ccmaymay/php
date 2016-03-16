<?php
set_time_limit(0);

$file = 'mat';
$matrix = [];

$csvfp = fopen($file, "r");

//print memory_get_usage(true)."\n";
$count = 1;
if($csvfp !== false) {
	while(! feof($csvfp)) {
		$row = fgets($csvfp); 
		if($row !== false) {
			$matrix = array_merge($matrix, explode(' ', $row));
			//if($count % 10 == 0) { print $count . "\n"; }
			$count++;
		}
		unset($row);
	}
}

//print memory_get_usage(true)."\n";

$n = count($matrix);
$norm = 0;

$start_time = microtime(true);

$number_of_entries = $n * $n;

foreach($matrix as $value) {
	$norm += $value * $value;
}

$norm = sqrt($norm);
$end_time = microtime(true);
$total_time = $end_time - $start_time;

print "Norm: " . $norm . "\n";
print "Execution time was: " . $total_time . " seconds\n";

