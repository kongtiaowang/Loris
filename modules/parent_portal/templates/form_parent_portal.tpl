
<div class="container">
    <div class="panel panel-default panel-center">
        <div class="panel-heading">
            <h3 class="panel-title">{$page_title}</h3>
        </div>
        <div class="panel-body">
                <form method="POST">
                    <p class="text-center">
                        Please enter your PSCID.
                    </p>
                    <div class="form-group">
                        {$form.pscid.html}
                        {if $form.pscid.error}
                            <span id="helpBlock" class="help-block">
                   <b class="text-danger">{$form.pscid.error}</b>
                 </span>
                        {/if}
                    </div>
                    <div class="form-group">
                        <input type="submit" name="submit" class="btn btn-primary btn-block"
                               value="Go To Parent Portal"/>
                    </div>
                </form>
        </div>
    </div>
</div>

