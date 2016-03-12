<?php
set_time_limit(0);

$file = 'mat';
$matrix = [];

$csvfp = fopen($file, "r");

if($csvfp !== false) {
	while(! feof($csvfp)) {
		$row = fgetcsv($csvfp, 0, ' '); 
		if($row !== false) {
			$matrix[] = $row;
		}
		unset($row);
	}
}

$n = count($matrix);
$norm = 0;

$start_time = microtime(true);

$number_of_entries = $n * $n;

$end_time = microtime(true);
$total_time = $end_time - $start_time;

print "Norm: " . $norm . "\n";
print "Execution time was: " . $total_time . " seconds\n";

