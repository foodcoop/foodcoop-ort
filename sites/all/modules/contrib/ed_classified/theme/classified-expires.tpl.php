<?php
/**
 * @file
 * Template for theme('classified_expires', $node).
 *
 * Variables:
 *
 * - $expires
 *   The date of expiration, in default classified.module format
 * - $expires_raw
 *   The date of expiration, as a UNIX timestamp
 * - $remaining
 *   The time remaining until expiration, in days
 * - $remaining_ratio
 *   The percentile ratio of remaining time to expiration over ad lifetime since
 *   creation.
 * - $remaining_class
 *   A class defining if the ad is expired, or has already spent most of its
 *   alloted lifetime
 *   - 'classified-expires-expired'
 *   - 'classified-expires-soon'
 *   - 'classified-expires-later'
 *
 * @copyright (c) 2010 Ouest Systemes Informatiques (OSInet)
 *
 * @author Frederic G. MARAND <fgm@osinet.fr>
 *
 * @license General Public License version 2 or later
 *
 * Original code, not derived from the ed_classified module.
 */


	// JM heavily modified this
	global $base_path;
	$reply_url = $base_path."node/".$node->nid."/reply";

	$my_user = user_load($node->uid);
	$myself = $my_user->uid == $user->uid;

	$whose = $myself ? "Your" : "This";

?><div class="classified-expires <?php echo $remaining_class; ?>"><?php
  echo t("<p>$whose ad will expire on @expires (@remaining remain).</p>", array(
    '@expires'   => $expires,
    '@remaining' => $remaining,
//     '@ratio'     => $remaining_ratio,
  ))?></div>


<?php if (!$myself) { ?>
	<h3>Reply to this Swap</h3>
	<p>Send a brief message to the member who posted this ad. Be sure to include any contact information you'd like them to use.</p>
	
	<form id="swap_reply_form" method="post" action="<?php print $reply_url; ?>">
		<textarea id="swap_reply_msg" name="swap_reply_msg"></textarea>
		<br>
		<small>Your reply will be sent via email, and will include the email address you provided to the shift swap system.</small>
		<br>
		<input type="submit" value="Send A Reply">
	</form>	 
<?php } ?>