<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta charset="utf-8"/>
<link rel="stylesheet" href="{$css}" type="text/css" />
<!-- shortcut icon that displays on the browser window -->
<link rel="shortcut icon" href="{$baseurl}/images/mni_icon.ico" type="image/ico" />

<title>DCC MRI Quality Control</title>
<style>
	h2 {
		text-align: center;
		text-weight: bold;
	}
	.has-error {
		color: #b94a48;
	}
	.success {
		color: #42a003;
	}
</style>

</head>
<body>
{section name=error loop=$error_message}
{$error_message[error]}<br />
{/section}

<p><a href="javascript:window.close()">Click here to close this window</a></p>
<div>

{if ($saved)}
<p class="success">Comments saved.</p>
{/if}

<table cellpadding="2" class="list">
{section name=data loop=$identifier}
    <tr>
        <th style="text-align:left">{$identifier[data].name}:</th>
        <td style="text-align:left">{$identifier[data].value}</td>
    </tr>
{/section}
</table>

{if $has_permission}
<form method="post">
{/if}

{foreach from=$comment item=curr_comment}
<h2>
{$curr_comment.label}
</h2>
	
	<table>
	{foreach from=$curr_comment['itms'] item=sub}
	<tr>
	<td>{$sub.label}</td><td>
	{if $sub.type=='select'}
	{html_options name=$sub.id options=$sub.options selected=$sub.selected}
	{elseif $sub.type=='text'}
	<textarea rows='3' cols='30' name={$sub.id}>{$sub.savedtext}</textarea>
	{/if}
	{if $sub.error}
		<div class="has-error">{$sub.error}</div>
	{/if}
	</td>
	
	</tr>
	{/foreach}
	</table>
	
{if !$has_permission}
<ul>
</ul>
{/if}

{/foreach}

{if $has_permission}
<input type="submit" name="fire_away" value="Save">
</form>
{/if}

</div>

</body>
</html>