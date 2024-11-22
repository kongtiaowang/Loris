{if $captcha_key}
<script src="https://www.google.com/recaptcha/api.js"></script>
{/if}
<div class="panel panel-default panel-center">
  <div class="panel-heading">
    <h3 class="panel-title">
        {htmlspecialchars($page_title, ENT_QUOTES, 'UTF-8')}
    </h3>
  </div>
  <div class="panel-body">
      {if $success}
    <div class="success-message">
      <h1>Thank you!</h1>
      <p>Your request for an account has been received successfully.</p>
      <a href="/" class="btn btn-primary btn-block">
        Return to Login Page
      </a>
    </div>
      {else}
    <p class="text-center">
      Please fill in the form below to request a LORIS account.<br/>
      We will contact you once your account has been approved.
    </p>
    <form method="POST" name="form1" id="form1">
      <div class="form-group">
          {htmlspecialchars($form.firstname.html, ENT_QUOTES, 'UTF-8')}
          {if $form.firstname.error}
            <span id="helpBlock" class="help-block">
              <b class="text-danger">{htmlspecialchars($form.firstname.error, ENT_QUOTES, 'UTF-8')}</b>
            </span>
          {/if}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.lastname.html, ENT_QUOTES, 'UTF-8')}
          {if $form.lastname.error}
            <span id="helpBlock" class="help-block">
              <b class="text-danger">{htmlspecialchars($form.lastname.error, ENT_QUOTES, 'UTF-8')}</b>
            </span>
          {/if}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.from.html, ENT_QUOTES, 'UTF-8')}
          {if $form.from.error}
            <span id="helpBlock" class="help-block">
              <b class="text-danger">{htmlspecialchars($form.from.error, ENT_QUOTES, 'UTF-8')}</b>
            </span>
          {/if}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.site.html, ENT_QUOTES, 'UTF-8')}
          {if $form.site.error}
            <span id="helpBlock" class="help-block">
              <b class="text-danger">{htmlspecialchars($form.site.error, ENT_QUOTES, 'UTF-8')}</b>
            </span>
          {/if}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.project.html, ENT_QUOTES, 'UTF-8')}
          {if $form.project.error}
            <span id="helpBlock" class="help-block">
              <b class="text-danger">{htmlspecialchars($form.project.error, ENT_QUOTES, 'UTF-8')}</b>
            </span>
          {/if}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.examiner.html, ENT_QUOTES, 'UTF-8')}
      </div>
      <div class="form-group">
          {htmlspecialchars($form.radiologist.html, ENT_QUOTES, 'UTF-8')}
      </div>
      <div class="form-group">
        {* Google reCaptcha. Don't display if a private key has not been configured *}
        {if $captcha_key}
            {htmlspecialchars($form.captcha.html, ENT_QUOTES, 'UTF-8')}
            <div class="g-recaptcha" data-sitekey="{htmlspecialchars($captcha_key, ENT_QUOTES, 'UTF-8')}"></div>
            <script src="https://www.google.com/recaptcha/api.js?render={htmlspecialchars($captcha_key, ENT_QUOTES, 'UTF-8')}&onload=onloadCallback nonce={htmlspecialchars($nonce, ENT_QUOTES, 'UTF-8')}"></script>
            {if $form.captcha.error}
                <span id="helpBlock" class="help-block">
                  <b class="text-danger">{htmlspecialchars($form.captcha.error, ENT_QUOTES, 'UTF-8')}</b>
                </span>
            {/if}
        {/if}
      </div>
      <div class="form-group">
        <input type="submit" name="Submit" class="btn btn-primary btn-block"
               value="Request Account"/>
      </div>
      <div class="form-group">
        <a href="/">Back to login page</a>
      </div>
        {/if}
  </div>
</div>

